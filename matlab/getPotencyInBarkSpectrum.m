function potency = getPotencyInBarkSpectrum(sampleData)
    %% defining initial variables for spectrum calculation
    potency = zeros(getSizeOfBarkSpectrum(),1);
    fourierTransform = sampleData.sample;
    sampleFreq = sampleData.samplingFrequency;
    
    %% Calculating the signal potency in the bark spectrum
    % each point in the fourier transform has an equivalent in frequency,
    % so we must find this equivalent and put it into the bark spectrum
    freq = getFrequencyFromSamples(sampleData);
    barkFreq = zeros(length(freq),1);
    for i = 1:length(freq)
        barkFreq(i) = convertToBarkSpectrum(freq(i));
    end
    % now that we have the frequencies in the bark spectrum, we sum the
    % potencies in each frequency
    for i = 1:length(fourierTransform)
        potency(barkFreq(i)) = potency(barkFreq(i)) + abs(fourierTransform(i))^2;
    end
end