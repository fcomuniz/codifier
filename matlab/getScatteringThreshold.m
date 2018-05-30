function t = getScatteringThreshold(scatteredPotency)
    beta = getTonalityCoefficient(scatteredPotency);
    j = 1:getSizeOfBarkSpectrum();
    l = beta*(14.5 + j) + (1-beta)*5.5;
    t = 10^((log10(scatteredPotency) - l/10);
end