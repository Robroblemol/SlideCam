# SlideCam
Slide Cam con Arduino
El arduino recive comandos por puerto serial y realiza los movimeinto o ajustes para el motor PAP 

# Comandos Slide
%100XXX% para ajustar las RPM del Motor paso a paso, XXX = cantidad de revoluciones 
%101000% para ajustar la direccion horaria o anti-horaria
%102XXX% mueve el Slide XXX pasos
%103000% optenemos la pocision actual del carro

