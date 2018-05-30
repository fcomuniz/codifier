% Programa wav2sgn - converte um sinal de audio gravado no formato "wav"
%                    em um sinal no formato "sgn". O formato "sgn" esta
%                    definido no roteiro da experiência 1 de 2016 da
%                    disciplina de Principios de Comunicaçoes%
% Parametros de Entrada:
%   nome do arquivo de audio de entrada - waveIn
%   nome do arquivo de saida - waveOut
%   Opção de extração:
%       0 - sinal da esquerda
%       1 - sinal da direita
%       2 - sinal mono
%       3 - diferença entre os canais
% Parametros de Saida:
%   indicador de erro - val (igual a zero em caso de erro)

function [val] = wav2sgn(waveIn,waveOut, opcao)

% Ajusta variavel de saida
val = 1;

% Le o tamanho do sinal de audio
aux = wavread(waveIn,'size');
nAmostras = aux(1);
nCanais = aux(2);
clear aux;

% Le o audio
[x,Fa,nBitsAudio] = wavread(waveIn);

% Verifica a opcao
switch opcao
    case 0
        % Cria arquivo de saida
        fid = fopen(waveOut,'w');
        
        % Escreve o arquivo de saida
        fwrite(fid,nAmostras,'int32');
        fwrite(fid,Fa,'float32');
        fwrite(fid,x(:,1),'float32');

        % Fecha o arquivo de saida
        fclose(fid);
        return;
    case 1
        if (nCanais ~=2)
            val = 0;
            disp('O sinal não é estereofonico');
        else
            % Cria arquivo de saida
            fid = fopen(waveOut,'w');
            
            % Escreve o arquivo de saida
            fwrite(fid,nAmostras,'int32');
            fwrite(fid,Fa,'float32');
            fwrite(fid,x(:,2),'float32');
            
            % Fecha o arquivo de saida
            fclose(fid);
        end
        return;
    case 2
        % Cria arquivo de saida
        fid = fopen(waveOut,'w');
        
        % Escreve o arquivo de saida
        fwrite(fid,nAmostras,'int32');
        fwrite(fid,Fa,'float32');
        if (nCanais == 1)
            fwrite(fid,x,'float32');
        else
            xm = mean(x,2);
            fwrite(fid,xm, 'float32');
        end
                
        % Fecha o arquivo de saida
        fclose(fid);
        return;
    case 3
        if (nCanais ~=2)
            val = 0;
            disp('O sinal não é estereofonico');
        else
            % Cria arquivo de saida
            fid = fopen(waveOut,'w');
            
            % Escreve o arquivo de saida
            fwrite(fid,nAmostras,'int32');
            fwrite(fid,Fa,'float32');
            d = x(:,1) - x(:,2);
            fwrite(fid,d,'float32');
            
            % Fecha o arquivo de saida
            fclose(fid);
        end
        return;
    otherwise
        val = 0;
        disp('Opcao indisponivel');
        return;
end