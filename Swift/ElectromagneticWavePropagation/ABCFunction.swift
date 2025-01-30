import Foundation
public func ABCFunc(){
    //INSERT ABC FUNCTION:
    
    
    //// correct
    let temp1 = sqrt(Cezh[0,0] * Chye[0,0])
    let temp2 = 1.0 / temp1 + 2.0 + temp1
    coef0 = -(1.0 / temp1 - 2.0 + temp1) / temp2
    coef1 = -2.0 * (temp1 - 1.0 / temp1) / temp2
    coef2 = 4.0 * (temp1 + 1.0 / temp1) / temp2
    //
    //
    //
    //
    //
    //        //ABC LEFT
    for nn in 0..<numberOfRows {
        let subExpr1 = Ez[2, nn] + EzLeft[0, 1, nn]
        let subExpr2 = EzLeft[0, 0, nn] + EzLeft[2, 0, nn]
        let subExpr3 = Ez[1, nn]
        let subExpr4 = EzLeft[1, 1, nn]
        let subExpr5 = coef2 * EzLeft[1, 0, nn] - EzLeft[2, 1, nn]
        
        Ez[0, nn] = coef0 * subExpr1 + coef1 * (subExpr2 - subExpr3 - subExpr4) + subExpr5
        
        
        // Memorize old fields
        for mm in 0..<3 {
            
            EzLeft[mm,1,nn] = EzLeft[mm,0,nn]
            EzLeft[mm,0,nn] = Ez[mm, nn]
        }
    }
    
    //
    //
    //
    //
    //ABCRIGHT
    for nn in 0..<numberOfRows {
        
        
        
        let A = Ez[numberOfColumns - 3,nn] + EzRight[0, 1, nn]
        let B = coef0 * A
        
        let C = EzRight[0, 0, nn] + EzRight[2, 0, nn] - Ez[numberOfColumns - 2,nn] - EzRight[1, 1, nn]
        
        let D = coef1 * C
        
        let E = coef2 * EzRight[1, 0, nn]
        
        Ez[numberOfColumns - 1,nn] = B + D + E - EzRight[2, 1, nn]
        
        // Memorize old fields
        for mm in 0..<3 {
            EzRight[mm,1,nn] = EzRight[mm,0,nn]
            EzRight[mm,0,nn] = Ez[numberOfColumns - 1 - mm,nn]
        }
    }
    
    
    
    
    
    
    
    
    //ABC BOTTOM
    for mm in 0..<numberOfColumns {
        
        
        let a =  Ez[mm, 2] + EzBottom[0, 1, mm]
        let b = EzBottom[0,0,mm] + EzBottom[2,0,mm] - Ez[mm,1] - EzBottom[1,1,mm]
        let d = coef0 * a
        
        
        let c = coef2 * EzBottom[1,0,mm]
        
        let e = coef1 * b
        
        
        
        
        Ez[mm, 0] = d + e + c - EzBottom[2,1,mm]
        
        // Memorize old fields
        for nn in 0..<3 {
            
            EzBottom[nn,1,mm] = EzBottom[nn,0,mm]
            EzBottom[nn,0,mm] = Ez[mm, nn]
        }
    }
    
    
    
    
    
    
    
    
    // ABC TOP
    for mm in 0..<numberOfColumns {
        let subExpr1 = Ez[mm, numberOfRows - 3] + EzTop[0, 1, mm]
        let subExpr2 = EzTop[0, 0, mm] + EzTop[2, 0, mm] - Ez[mm, numberOfRows - 2] - EzTop[1, 1, mm]
        let subExpr4 = coef2 * EzTop[1, 0, mm]
        
        let subExpr5 = EzTop[2, 1, mm]
        
        Ez[mm, numberOfRows - 1] = coef0 * (subExpr1) + coef1 * (subExpr2) + subExpr4 - subExpr5
        
        // Memorize old fields
        for nn in 0..<3 {
            
            EzTop[nn,1,mm] = EzTop[nn,0,mm]
            EzTop[nn,0,mm] = Ez[mm, numberOfRows - 1 - nn]
        }
    }
    
    
    
}
