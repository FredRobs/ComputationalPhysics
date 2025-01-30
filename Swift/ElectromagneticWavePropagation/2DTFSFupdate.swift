import Foundation



public func UpdateTFSFunction(time: Int, Xsize: Int){
    
    
    
    
    //INERT TFSF UPDATE EQUATIONS:
    
    
    //Insert corrections in Hy and hx
    
    // Correct Hy along left edge
    
    for nnn in firstY...lastY {
        
        let mmm = firstX - 1
        
        
        Hy[mmm,nnn] -= Chye[mmm, nnn] * Ez1Daux[mmm + 1]
    }
    
    
    
    // Correct Hy along right edge
    
    for nnn in firstY...lastY {
        
        let mmm = lastX
        
        Hy[mmm,nnn] += Chye[mmm, nnn] * Ez1Daux[mmm]
    }
    
    
    // Correct Hx along bottom
    
    for mm in firstX...lastX {
        
        let nnn = firstY - 1
        
        
        
        Hx[mm,nnn] += Chxe[mm, nnn] * Ez1Daux[mm]
    }
    
    
    // Correct Hx along top
    
    for mm in firstX...lastX {
        
        let nnn = lastY
        
        Hx[mm,nnn] -= Chxe[mm, nnn] * Ez1Daux[mm]
    }
    
    
    
    
    // update auxillary 1D
    
    //  Hy1DAux[Xsize - 1] = Hy1DAux[Xsize - 2]
    //1d HY
    for mm in 0..<(Xsize - 1) {
        Hy1DAux[mm] = Chyh1Daux[mm] * Hy1DAux[mm] + Chye1Daux[mm] * (Ez1Daux[mm + 1] - Ez1Daux[mm])
    }
    
    Ez1Daux[Xsize - 1] = Ez1Daux[Xsize - 2] //simple ABC auxillarynode rhs as required pg 207
    //Ez1Daux[0] = Ez1Daux[1]
    
    //1d hx
    for mm in 1..<(Xsize - 1) {
        Ez1Daux[mm] = Ceze1Daux[mm] * Ez1Daux[mm] + Cezh1Daux[mm] * (Hy1DAux[mm] - Hy1DAux[mm - 1])
    }
    
    
    
  
    let qTimeSubtract30 = Double(time) - 30.0
    
  Ez1Daux[0] = exp(-(qTimeSubtract30) * (qTimeSubtract30) / 100.0)
    
    
    
    
    // //  insert corrections in ez
    
    //Correct Ez along left edge
    
    for nn in firstY...lastY {
        
        let mm = firstX
        
        
        Ez[mm,nn] -= Cezh[mm, nn] * Hy1DAux[mm - 1]
    }
    
    
    
    // Correct Ez along right edge
    
    for nn in firstY...lastY {
        
        let  mm = lastX
        
        Ez[mm, nn] += Cezh[mm, nn] * Hy1DAux[mm]
    }
    
    
    
    
}
