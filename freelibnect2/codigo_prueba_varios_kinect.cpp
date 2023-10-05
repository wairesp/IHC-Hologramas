// libfreenect_test_2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <libfreenect2/libfreenect2.hpp>
#include <libfreenect2/frame_listener_impl.h>
#include <libfreenect2/registration.h>
#include <libfreenect2/packet_pipeline.h>
#include <libfreenect2/logger.h>
#include <libfreenect2/libfreenect2.hpp>
#include <libfreenect2/frame_listener_impl.h>
#include <fstream>
#include <cstdlib>



class MyFileLogger : public libfreenect2::Logger
{
private:
    std::ofstream logfile_;
public:
    MyFileLogger(const char* filename)
    {
        if (filename)
            logfile_.open(filename);
        level_ = Debug;
    }
    bool good()
    {
        return logfile_.is_open() && logfile_.good();
    }
    virtual void log(Level level, const std::string& message)
    {
        logfile_ << "[" << libfreenect2::Logger::level2str(level) << "] " << message << std::endl;
    }
};



int main() {
    libfreenect2::Freenect2 freenect2;
    libfreenect2::Freenect2Device* dev1 = freenect2.openDefaultDevice();
    libfreenect2::Freenect2Device* dev2 = freenect2.openDevice(1); // Assuming device index 1 for the second device

    if (dev1 == 0 || dev2 == 0) {
        std::cout << "Error: Could not open device!" << std::endl;
        return -1;
    }

    libfreenect2::SyncMultiFrameListener listener(libfreenect2::Frame::Color | libfreenect2::Frame::Depth | libfreenect2::Frame::Ir);
    libfreenect2::FrameMap frames;

    dev1->setColorFrameListener(&listener);
    dev1->setIrAndDepthFrameListener(&listener);
    dev1->start();

    dev2->setColorFrameListener(&listener);
    dev2->setIrAndDepthFrameListener(&listener);
    dev2->start();

    // Now both devices are running and you can retrieve frames from the listener.
    // Remember to stop the devices and close them when you're done.

    dev1->stop();
    dev1->close();

    dev2->stop();
    dev2->close();

    return 0;
}
