import Foundation




public func updateMagnetic(_1or2: Int, time: Int ){
    

    
    if _1or2 == 1 {
        
           
            magnetic_field[SIZE - 1] = magnetic_field[SIZE - 2]
            for mm in 0..<(SIZE - 1) {
                magnetic_field[mm] = chyh[mm] * magnetic_field[mm] + chye[mm] * (electric_field[mm + 1] - electric_field[mm])
            }
        
       let  qTimeSubtract30 = Double(time) - 30.0
        
            magnetic_field[hardwireSourceNode - 1] -= exp(-(qTimeSubtract30) * (qTimeSubtract30) / 100.0) / imp0
        
        
        
        
        
    }
    else{
        
        
        
        //UPDATE HX 2D: correct
        for m in 0..<numberOfColumns { //101
            
            for n in 0..<numberOfRows - 1{ //80
                

                let a = Chxh[m, n] * Hx[m, n]
                
                let b = Ez[m, n + 1] - Ez[m, n]
                
                let c = Chxe[m, n] * b
                
                let d = a - c
                
                
                
                
                Hx[m, n] = d
            }
        }
        
        //UPDATE HY 2D: correct
        for m in 0..<numberOfColumns - 1{ //100
            
            for n in 0..<numberOfRows {//81
                

                let a = Chyh[m, n] * Hy[m, n]
                
                let b = Ez[m + 1, n] - Ez[m, n]
                
                let c = Chye[m , n] * b
                
                let d = a + c
                
                
                Hy[m, n] = d
                
                
                
            }
        }
        
        
        
    }



}



public func updateElectric(_1or2: Int, time: Int){
    
    
    if _1or2 == 1 {
        
        
        electric_field[0] = electric_field[1]
        electric_field[SIZE - 1] = electric_field[SIZE - 2]
        
        for mm in 1..<SIZE {
            let deltaHy = (magnetic_field[mm] - magnetic_field[mm - 1])
            
            
            electric_field[mm] = ceze[mm] * electric_field[mm] + cezh[mm] * deltaHy
        }
        
        let  qTimeSubtract30 = Double(time) - 30.0
        electric_field[hardwireSourceNode] += exp(-(qTimeSubtract30) * (qTimeSubtract30) / 100.0)
        
        
    } else {
        
        
        for m in 1..<numberOfColumns - 1{
            
            for n in 1..<numberOfRows - 1 {
                
                
                let a = Ceze[m, n] * Ez[m, n]
                
                let b = (Hy[m, n] - Hy[m - 1, n])
                
                let c = (Hx[m, n] - Hx[m, n - 1])
                
                let d = b - c
                
                let e = Cezh[m, n] * d
                
                
                
                Ez[m, n] = a + e
                
                
                
            }
        }
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
}
