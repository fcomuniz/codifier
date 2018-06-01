function t = getScatteringThreshold(scatteredPotency)
    beta = getTonalityCoefficient(scatteredPotency);
    sizeOfBarkSpectrum = 1:getSizeOfBarkSpectrum();
    l = beta*(14.5 + sizeOfBarkSpectrum) + (1-beta)*5.5;
    l = l';
    t = 10.^((log10(scatteredPotency) - l/10));
end