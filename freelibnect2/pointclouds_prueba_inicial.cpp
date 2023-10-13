#include <iostream>
#include <libfreenect2/libfreenect2.hpp>
#include <libfreenect2/frame_listener_impl.h>
#include <fstream>

struct Point3f {
    float x, y, z;
};


int main() {
    libfreenect2::Freenect2 freenect2;

    if (freenect2.enumerateDevices() == 0) {
        std::cout << "No Kinect v2 devices found!" << std::endl;
        return -1;
    }

    libfreenect2::Freenect2Device* dev = freenect2.openDefaultDevice();

    if (dev == 0) {
        std::cout << "Failed to open Kinect v2 device!" << std::endl;
        return -1;
    }

    // receive color and depth frames
    libfreenect2::SyncMultiFrameListener listener(libfreenect2::Frame::Color | libfreenect2::Frame::Depth);

    // register the FrameListener with the device
    dev->setColorFrameListener(&listener);
    dev->setIrAndDepthFrameListener(&listener);

    dev->start();

    std::cout << "Kinect v2 device serial: " << dev->getSerialNumber() << std::endl;
    std::cout << "Kinect v2 device firmware: " << dev->getFirmwareVersion() << std::endl;

    // from the Kinect v2 device
    libfreenect2::FrameMap frames;
    int frameCount = 0;

    while (frameCount < 100) { // Capture 100 frames
        listener.waitForNewFrame(frames);

        libfreenect2::Frame* depth = frames[libfreenect2::Frame::Depth];

        // Create a point cloud
        std::vector<Point3f> pointCloud;
        pointCloud.reserve(depth->width * depth->height);

        // Generate the point cloud data
        for (int y = 0; y < depth->height; ++y) {
            for (int x = 0; x < depth->width; ++x) {
                float z = reinterpret_cast<float*>(depth->data)[y * depth->width + x];

                // Convert from pixel coordinates to real-world coordinates
                Point3f point;
                point.x = (x - depth->width / 2.0f) * z;
                point.y = (y - depth->height / 2.0f) * z;
                point.z = z;

                pointCloud.push_back(point);
            }
        }

        // Save the point cloud to a text file
        std::ofstream file("pointcloud" + std::to_string(frameCount) + ".txt");
        for (const auto& point : pointCloud) {
            file << point.x << " " << point.y << " " << point.z << "\n";
        }
        file.close();
        std::cout << "pointcloud" + std::to_string(frameCount) + ".txt saved" << std::endl;
        listener.release(frames);

        ++frameCount;
    }


    dev->stop();
    dev->close();

    return 0;
}
