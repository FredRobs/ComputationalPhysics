function mandelbrotSet(realMin, realMax, imagMin, imagMax, width, height, maxNumOfTrys)
    realPart = range(realMin, realMax, length=width);
    imagPart = range(imagMin, imagMax, length=width);
    mandelbrot = zeros(Int, height, width);

    for i in 1:width
        for j in 1:height

            z = realPart[i] + im * imagPart[j];
            c = z;
            NumOfTrys = 0

            while abs(z) < 2 && NumOfTrys < maxNumOfTrys
                z = z^2 + c
                NumOfTrys += 1
            end

            mandelbrot[j,i] = NumOfTrys
        end
    end
    return mandelbrot
end

function burningShipSet(realMin, realMax, imagMin, imagMax, width, height, maxNumOfTrys)
    realPart = range(realMin, realMax, length=width);
    imagPart = range(imagMin, imagMax, length=width);
    burningShip = zeros(Int, height, width);

    for i in 1:width
        for j in 1:height

            z = 0 + 0 * im;
            c = realPart[i] + im * imagPart[j];
            NumOfTrys = 0

            while abs(z) < 3 && NumOfTrys < maxNumOfTrys
                z = (abs(real(z)) + im * abs(imag(z)))^2 + c
                NumOfTrys += 1
            end

            burningShip[j,i] = NumOfTrys
        end
    end
    return burningShip
end

function juliaSet(realMin, realMax, imagMin, imagMax, width, height, maxNumOfTrys, c)
    realPart = range(realMin, realMax, length=width);
    imagPart = range(imagMin, imagMax, length=width);
    julia = zeros(Int, height, width);

    for i in 1:width
        for j in 1:height

            z = realPart[i] + im * imagPart[j];
            NumOfTrys = 0

            while abs(z) < 3 && NumOfTrys < maxNumOfTrys
                z = z^2 + c
                NumOfTrys += 1
            end

            julia[j,i] = NumOfTrys
        end
    end
    return julia
end
