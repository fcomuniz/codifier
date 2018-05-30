% Programa leSgn - le um sinal no formato "sgn" e retorna o sinal,
%                  o número de amostras e a frequencia de amostragem.
%                  O formato "sgn" esta definido no roteiro da
%                  1a experiência
%
% Parametros de Entrada:
%   nome do arquivo de audio de entrada - waveIn
% Parametros de Saida:
%   sinal - o sinal
%   nAmostras - número de amostras
%   Fa - frequencia de amostragem

function [sinal,nAmostras,Fa] = leSgn(waveIn)

% Abre o arquivo .sgn de entrada
fid = fopen(waveIn,'r');

% Le o arquivo de entrada
nAmostras = fread(fid,1,'int32');
Fa = fread(fid,1,'float32');
x = fread(fid,[1 nAmostras],'float32');
sinal = transpose(x);

% Fecha o arquivo de entrada
fclose(fid);