function beta = getTonalityCoefficient(scatteredPotency)
    mg = geomean(scatteredPotency);
    ma = mean(scatteredPotency);
    SFM = 10*log10(mg/ma);
    SFMmax = -60;
    beta = min(SFM/SFMmax, 1);

end