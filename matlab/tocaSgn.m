% Programa tocaSgn - Toca o sinal sgn (supondo um sinal de audio) 
%                    O formato "sgn" esta definido no roteiro da 1a
%                    experiência do laboratório
%
% Parametros de Entrada:
%   nome do arquivo sgn de entrada - waveIn
%   duraçao, em segundos, que se deseja tocar - T
% Parametro de saida:
%    objeto para ser tocado com o play(p)

function [p] = tocaSgn(waveIn,T)

% Abre o arquivo .sgn de entrada
fid = fopen(waveIn,'r');

% Le o header do arquivo de entrada
nAmostras = fread(fid,1,'int32');
Fa = fread(fid,1,'float32');
nAmostras = min(nAmostras,T*Fa);
x = fread(fid,[1 nAmostras],'float32');
%x = transpose(x);

% Fecha o arquivo de entrada
fclose(fid);

% Cria o objeto
p = audioplayer(x,Fa);
play(p);
