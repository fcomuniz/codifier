function scattering = getScatteringMatrix()
    n = getSizeOfBarkSpectrum();
    scattering = zeros(n);
    for i = 1:n
       for j = i:n
          scattering(j,i) = 10^((15.81 + 7.5*(i-j) - 17.5*sqrt( 1 + ((i-j) + 0.474)^2) )/10); 
       end
    end
end