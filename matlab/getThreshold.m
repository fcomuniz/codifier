function threshold = getThreshold(scatteredThreshold, scatteringMatrix)
%GETTHRESHOLD Summary of this function goes here
%   Detailed explanation goes here
threshold = scatteredThreshold./sum(scatteringMatrix)';
tSPL = getSoundPressureLevelThreshold();
threshold = max(threshold, tSPL);
end

