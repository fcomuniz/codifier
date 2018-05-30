function convertedValue = convertToBarkSpectrum(frequency)
    lowb = [0,100,200,300,400,510,630,770,920,1080,1270,1480,1720,2000,2320,2700,3150,3700,4400,5300,6400,7700,9500,12000,15500];
    upb = [lowb(2:end),22050];
    index = 1;
    while(index <= length(upb) && frequency >= upb(index))
        index = index+1;
    end
    if(index == length(upb)+1)
        index = index-1;
    end
    convertedValue = index;
end