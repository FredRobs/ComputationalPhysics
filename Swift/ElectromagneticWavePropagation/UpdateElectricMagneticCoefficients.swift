import Foundation

public func UpdateElectricMagenticCoefficients2D(courantDIVimp: Double, courantximp: Double)
{
    //electric field COEFFICIENTS updates
    
    for m in 0..<numberOfColumns{
        for n in 0..<numberOfRows{
            Ceze[m,n] = 1.0
            Cezh[m,n] = courantximp
            
        }
        
    }
    
    
    
    //MAgnetic field COEFFICIENTS updates
    
    
    
    for m in 0..<numberOfColumns{
        for n in 0..<numberOfRows - 1{
            
            Chxh[m,n] = 1.0
            Chxe[m,n] = courantDIVimp
            
        }
    }
    
    for m in 0..<numberOfColumns - 1{
        for n in 0..<numberOfRows{
            
            Chyh[m,n] = 1.0
            Chye[m,n] = courantDIVimp
            
        }
        
    }
}
