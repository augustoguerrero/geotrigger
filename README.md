# Sistema de Detección de Caída Libre con Arduino y NRF24L01

## Objetivo
Detectar la caída libre de una masa utilizando un sensor piezoeléctrico y enviar la letra "t" a una computadora a través de comunicación inalámbrica, simulando un disparador para grabaciones o experimentos geologicos.

## Descripción
El sistema consta de dos módulos Arduino:
1. **Arduino Pro Mini (Transmisor)**: Con un sensor piezoeléctrico conectado a la entrada analógica A0 y un módulo NRF24L01. Detecta la vibración de la caída (umbral > 500) y envía el caracter 't' de forma inalámbrica.
2. **Arduino Pro Micro (Receptor)**: Con otro módulo NRF24L01 y funcionalidad HID. Recibe el caracter 't' y lo envía a la computadora por USB, actuando como teclado y gatillando la grabación de datos usando geofonos.

## Funcionamiento
- El sensor piezoeléctrico detecta la vibración de la masa al caer.
- Si la señal supera el umbral, el Pro Mini envía 't' vía NRF24L01.
- El Pro Micro recibe 't' y lo escribe en la computadora como entrada de teclado.
- Comunicación inalámbrica hasta ~100m (linea de visión) con NRF24L01.

## Conexiones NRF24L01
- **Pro Mini y Pro Micro**:
  - VCC: 3.3V
  - GND: GND
  - CE: Pin 7
  - CSN: Pin 8
  - SCK: Pin 13
  - MOSI: Pin 11
  - MISO: Pin 12
- **Sensor Piezoeléctrico**: A0 en Pro Mini.
- Usar capacitor 10µF entre VCC/GND del NRF24L01.

## Requisitos
- Librerías: `RF24` (NRF24L01), `Keyboard` (Pro Micro).
- Alimentación: 3.3V estable para NRF24L01.
- Arduino IDE para cargar el código.

## Uso
1. Conectar los componentes según las conexiones.
2. Cargar el código del transmisor al Pro Mini y del receptor al Pro Micro.
3. Abrir un editor de texto en la computadora.
4. Provocar una caída libre cerca del sensor; la letra 't' aparecerá en el editor.

## Notas
- Ajustar el umbral (500) según la sensibilidad del sensor.
- Verificar conexiones y alimentación antes de usar.
- Rango inalámbrico puede variar por obstáculos o interferencias.
