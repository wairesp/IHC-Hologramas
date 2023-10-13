# Instalación de freelibnect2

## Pasos
1. Ir al path de vcpkg con el comando `cd freelibnect2 && cd vcpkg` 
   (opcional) sino funcionan los pasos posteriores clonar este repositorio `https://github.com/Microsoft/vcpkg`
2. En la carpeta vcpkg correr `.\bootstrap-vcpkg.bat`
3. Después correr `.\vcpkg integrate install`
4. Finalmente correr `.\vcpkg install libfreenect2`

5. Instalación de libusbK a través de Zadig: Luego, utilizamos Zadig para instalar libusbK en el Xbox NUI Sensor (composite parent). LibusbK es una biblioteca que proporciona soporte genérico para dispositivos USB.

Nota: Verificamos que no estemos utilizando controladores ASMedia, ya que estos no funcionan correctamente con nuestro hardware.

## Uso
1. Con Visual Studio Community 2022, creamos un proyecto nuevo que utilice la consola.
2. Dentro de las propiedades del proyecto, asegurarse que dentro de Configuration properties > Linker > System se tenga a `Console(/SUBSYSTEM:CONSOLE)` como valor en SubSystem.
3. Pegar el archivo de prueba de este repositorio.
4. ¡Listo!

## Documentación 
Puedes encontrar más información en la documentación oficial: `https://openkinect.github.io/libfreenect2/files.html`
