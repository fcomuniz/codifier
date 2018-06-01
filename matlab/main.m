close all;
load handel.mat;
y2 = y(1:2048);
f = SampleData(y2, Fs);
barkPotency = getPotencyInBarkSpectrum(f);
scatteredPotency = getScatteredCriticalBandPotency(barkPotency);
scatteredThreshold = getScatteringThreshold(scatteredPotency);
threshold = getThreshold(scatteredThreshold, getScatteringMatrix());
figure()
stairs(10*log10(barkPotency));
hold on;
stairs(10*log10(scatteredPotency));
hold on;
% figure()
stairs(10*log10(threshold));


%% calculation of the spectral peak

spectralPeaks = calculateSpectralPeaks(f);