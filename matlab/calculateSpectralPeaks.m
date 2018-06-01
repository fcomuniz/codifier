function spectralPeaks = calculateSpectralPeaks(sampleData)
    Sr = abs(real(sampleData.fourierTransform));
    Si = abs(imag(sampleData.fourierTransform));
    for i = 1:128
        spectralPeaks(i) = max(max(Sr(8*(i-1) + 1:8*i)), max(Si(8*(i-1) + 1:8*i)));
    end
end