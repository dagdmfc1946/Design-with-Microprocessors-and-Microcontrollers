% PARCIAL 4 - DISEÑO CON uP y uC. 2024-1.
% NOMBRE: Diego Andrés García Díaz.
% CÓDIGO: 2195533.

clc
clear

muestras = 0:1:360; % Número de muestras a tomar (Cada grado).

ampl_sen_V = 4*abs(sin(deg2rad(muestras))); % Se define el valor de amplitud para cada grado.

conv = round((ampl_sen_V*4095)/(5)); % Se redondea a un valor entero y se hace la conversión digital 
                                     % de cada valor de amplitud generado.

% disp(conv); % Se muestran los valores ya convertidos digitalmente.

vector_sen = sprintf('%.1d, ',conv) % Se muestra un vector con los valores digitales con los que se generará la señal seno.