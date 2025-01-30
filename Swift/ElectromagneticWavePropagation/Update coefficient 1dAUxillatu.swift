import Foundation

public func UpdateCoefficients1DAuxillary(courantDIVimp: Double, courantximp: Double){
    //electric field COEFFICIENTS updates
    
    for mm in 0..<Xsize - 1 {
        
        if mm < (Xsize - 1 - Nloss){
            Ceze1Daux[mm] = 1.0
            Cezh1Daux[mm] = courantximp
            Chyh1Daux[mm] = 1.0
            Chye1Daux[mm] = courantDIVimp
            
        }
        
        else {
            
            
            let a  = Double(Xsize) - 1.0 - Double(Nloss)
            var dephtInLayer = Double(mm) - Double((a)) + 0.5
            let b = dephtInLayer / Double(Nloss)
            var lossFactor = MaxLoss * pow(b,2)
            
            let c = 1.0 - lossFactor
            let d = 1.0 + lossFactor
            
            Ceze1Daux[mm] = c / d
            Cezh1Daux[mm] = courantximp / d
            
            dephtInLayer += 0.5
            
            let e = dephtInLayer / Double(Nloss)
            
            lossFactor =  MaxLoss * pow(e, 2)
            
            let f = 1.0 - lossFactor
            let g = 1.0 + lossFactor
            
            Chyh1Daux[mm] = f / g
            Chye1Daux[mm] = courantDIVimp / g
            
            
        }
    }


    
    
    
    
    
}
