classdef SampleData
   properties
       sample
       fourierTransform
       samplingFrequency
   end
   methods
       function obj = SampleData(y, Fs)
        obj.sample = y;
        obj.samplingFrequency = Fs;
        obj.fourierTransform = fft(y);
       end
   end
    
end