% Programa visualizaDEP - Visualiza a DEP do sinal sgn
%                              O formato "sgn" esta definido no roteiro da
%                              1a experiência
%
% Parametros de Entrada:
%   nome do arquivo do sinal de entrada - sgnIn
%   Tempo da janela: T (em segundos) - não habilitado
%   tipo de janelamento - janela --- 0 = retangular  - não habilitado
%                                    1 = hanning - não habilitado

%function [val] = visualizaDEP(sgnIn,T,janela)
function [val] = visualizaDEP(sgnIn)

% Ajusta variavel de saida
val = 1;
janela = 0;
T = 0.1;

% Abre o arquivo .sgn de entrada
nBitsAudio = 16;
fid = fopen(sgnIn,'r');

% Le o header do arquivo de entrada
nAmostras = fread(fid,1,'int32');
Fa = fread(fid,1,'float32');

% Calcula o numero de blocos
tamBloco = floor(T*Fa);
nBlocos = ceil(2*nAmostras/tamBloco-1);

% Plota
NN = floor(tamBloco/2);
indices =0:NN;
indices = (indices/tamBloco)*Fa;
switch janela
    case 0
        for i=1:nBlocos,
            pos = (i-1)*(tamBloco/2)*4+8;
            fseek(fid, pos,-1);
            x = fread(fid,[1 tamBloco],'float32');
            x = [x zeros(1,tamBloco - size(x,2))];
            espectro = abs(fft(x(1,:)))+1e-50;
            dep = power(espectro(1:NN+1)*sqrt(2)/(tamBloco*power(2,1-nBitsAudio)),2);
            depDB = 10*log10(dep);
            plot(indices,depDB);
            axis([indices(1)  indices(NN+1)  -40 90])
            pause(T)
        end
    case 1
        formaJanela = transpose(hanning(tamBloco));
        for i=1:nBlocos,
            pos = (i-1)*(tamBloco/2)*4+8;
            fseek(fid, pos,-1);
            x = fread(fid,[1 tamBloco],'float32');
            x = [x zeros(1,tamBloco - size(x,2))];
            x(1,:) = x(1,:).*formaJanela;
            espectro = abs(fft(x(1,:)))+1e-50;
            dep = power(espectro(1:NN+1)*sqrt(2)/(tamBloco*power(2,1-nBitsAudio)),2);
            depDB = 10*log10(dep);
            plot(indices,depDB);
            axis([indices(1)  indices(NN+1)  -40 90])
            pause(T)
        end
end

% Fecha o arquivo de entrada
fclose(fid);