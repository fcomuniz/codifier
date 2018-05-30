%% function for getting the frequency from the fourier transform and the sampling frequency
function f =  getFrequencyFromSamples(sampleData)
f = sampleData.samplingFrequency/2*triangularPulse(1,length(sampleData.fourierTransform)+1,1:length(sampleData.fourierTransform));
end