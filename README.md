# Proyecto Holograma con Kinects

Este proyecto se enfoca en la creación de un holograma de una persona utilizando más de dos sensores Kinect para dispositivos de Realidad Virtual (RV) o Realidad Aumentada (RA). El objetivo principal es lograr una comunicación más realista en entornos virtuales.

Para alcanzar este objetivo, dividimos el proyecto en seis partes fundamentales:

## 1. Captura de Datos y Calibración de los Kinects
En esta etapa inicial, se capturan datos de profundidad y, posiblemente, datos de color utilizando los sensores Kinect. La calibración de los Kinects se realiza mediante el algoritmo desarrollado por el profesor LOAIZA FERNANDEZ MANUEL EDUARDO .

## 2. Conversión de Datos
En esta fase, se emplea un algoritmo para combinar los datos de puntos (point clouds) capturados por los Kinects y generar un objeto tridimensional. Se utilizan técnicas como el algoritmo Iterative Closest Point (ICP) para asegurar una superposición precisa de las nubes de puntos.

## 3. Limpieza del Objeto
Luego de la fusión de las nubes de puntos, se realiza un procesamiento adicional para limpiar el objeto resultante. Esto puede incluir la eliminación de puntos atípicos, suavizado adicional o segmentación para identificar partes específicas del cuerpo.

## 4. Creación de una Representación 3D
A partir de la nube de puntos fusionada, se genera una representación 3D más completa de la persona. Esto puede implicar la creación de una malla poligonal que conecta los puntos de la nube.

## 5. Exportación a Unity
Una vez obtenida una representación 3D de la persona, se exporta a un formato compatible con Unity, como un material o un objeto dinámico.

## 6. Compresión del Modelo
El modelo 3D se actualizará dinámicamente en la escena de Unity utilizando recursos web, y se comprimirá para lograr una representación en tiempo real.

Este repositorio contiene el código y los recursos necesarios para llevar a cabo este proyecto de hologramas con múltiples sensores Kinect. ¡Esperamos que esta iniciativa contribuya a una comunicación más inmersiva en entornos de RV y RA!
