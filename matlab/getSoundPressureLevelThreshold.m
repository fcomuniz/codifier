function tSPL = getSoundPressureLevelThreshold()
%GETSOUNDPRESSURELEVELTHRESHOLD Summary of this function goes here
%   Detailed explanation goes here
centerBand = 1e-3*[50 150 250 350 450 570 700 840 1000 1170 1370 1600 1850 2150 2500 2900 3400 4000 4800 5800 7000 8500 10500 13500 19500];
tSPL = 3.64*centerBand.^(-0.8) - 6.5*exp(-0.6*(centerBand-3.3).^2) + 0.001*centerBand.^4;
tSPL = tSPL';
end

