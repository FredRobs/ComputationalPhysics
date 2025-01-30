function initialiseQuantumWell(WellPotential,U_x,wellWidth,numOfGridPoints,x)
    for i in 1:1:numOfGridPoints
        if x[i] > -wellWidth/2 && x[i] < wellWidth/2
            # Set all x points within the well to be equal to the potential
            WellPotential[i] = U_x;
        end
    end
    return WellPotential;
end

function initialiseDoubleGaussianWell(WellPotential,U_x,numOfGridPoints,x,sigma,seperationDistance)
    xmin = -(seperationDistance / 2) - (4 * sigma);
    xmax = (seperationDistance / 2) + (4 * sigma);
    #Create the max and min points based on the value for sigma

    for i in 1:1:numOfGridPoints
        if x[i] < xmax && x[i] > xmin
            # First gaussian curve
            WellPotential[i] = U_x * exp(-((x[i] + seperationDistance / 2)^2) / (2 * sigma^2))
        end
        if x[i] < xmax && x[i] > xmin
            # Second gaussian curve
            WellPotential[i] += U_x * exp(-((x[i] - seperationDistance / 2)^2) / (2 * sigma^2))
        end
        #if x[i] > -seperationDistance/2 && x[i] < seperationDistance/2
            #WellPotential[i] = 0;
        #end
    end
    return WellPotential;
end

function initialiseQuadraticQuantumWell(WellPotential,U_x,wellWidth,numOfGridPoints,x)
    for i in 1:1:numOfGridPoints
        if x[i] > -wellWidth/2 && x[i] < wellWidth/2
            # Set points with the well width to be equal to the parabolic function 
            WellPotential[i] = U_x * (1-(2 * x[i]/wellWidth)^2);
        end
    end
    return WellPotential;
end

function addNotch(WellPotential,notchPotetial,notchWidth)
    for i in 1:1:numOfGridPoints
        if x[i] > -notchWidth/2 && x[i] < notchWidth/2
            # Set a potential values within the notch width to be eqaul to the notch potential
            WellPotential[i] = notchPotetial;
        end
    end
    return WellPotential;
end

function initialiseDoubleQuantumWell(WellPotential,U_x,wellWidth,numOfGridPoints,x,seperationDistance)
    for i in 1:1:numOfGridPoints
        if x[i] > -(seperationDistance/2)-wellWidth && x[i] < -seperationDistance/2
            # Set well Potetial to U_x in the first well
            WellPotential[i] = U_x;
        end
        if x[i] > seperationDistance/2 && x[i] < (seperationDistance/2)+wellWidth
            # Set well Potetial to U_x in the second well
            WellPotential[i] += U_x;
        end
    end
    return WellPotential;
end

function createHamiltonain(t, numOfGridPoints)
        diag1 = fill(t,numOfGridPoints-1); # Fill first tridiagonal with the value t
        diag3 = fill(t,numOfGridPoints-1); # Fill second tridiagonal with the value t
        for i in 1:1:numOfGridPoints
            diag2[i] = -(2 *t).+WellPotential[i]; # Fills the diagonal with -2t + well Potetial
        end
        hamiltonian = diagm(0 => diag2, 1 => diag1,-1 => diag3); # Creates a new diagonal matrix from the previous diagonals 
    return hamiltonian
end

function addEigenValue(numOfGridPoints,energyEigenVectors,energyEigenValues)
    for i in 1:1:numOfGridPoints
        # Adds the eigenvalues to the energy eigen vectors
        energyEigenVectors[:,i]=energyEigenVectors[:,i].+energyEigenValues[i];
    end
    return energyEigenVectors;
end

function normaliseWavefunction(numOfGridPoints,energyEigenVectors, dx)
    for i in 1:1:numOfGridPoints
        # Creates a normilising factor then applies this factor to a energy eigenvector matrix
        normFactor = sqrt(sum(abs2.(energyEigenVectors[:,i])) * dx);
        energyEigenVectors[:,i] .= energyEigenVectors[:,i] / normFactor;
    end
    return energyEigenVectors;
end




