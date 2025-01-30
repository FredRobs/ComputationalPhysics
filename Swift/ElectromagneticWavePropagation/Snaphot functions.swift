import Foundation


public func generateSnapshot1D(dt: Int){
   // Check of time is at a multiple of 10
   if(dt % 10 == 0)
   {
       // Create a new file and update frame
       let filename = "\(basename).\(frame)"
       let fileout = FileWriter(fileName: filename)
       frame += 1
       var data = ""
       // Copy
       for mm in 0 ..< SIZE {
           data += "\(electric_field[mm] + (Double(frame)-1))\n"
       }
       fileout.write_data(data: data)
   }
}



public func snapshot2d(qtime: Int, ez: twoDGrid, temporalStride: Int) {
   
    func checkTemporalStride(_ temporalStride: Int) {
        if temporalStride < -1 {
            fputs("Temporal stride must be set to positive value\n", stderr)
            exit(-1)
        }
    }
    
  let E = ez
   
    let maxvalue = MaxValue(data: ez.data)

   
    
    if(qtime % 10 == 0){
        
        var filename = ""
        
        
        filename = "\(basename).\(frame)"
        
        let fileout = FileWriter(fileName: filename)
        
        frame += 1
        
        
        var data = " "

        
        for n in stride(from: SizeY - 1, through: 0, by: -1) {
               
            for m in stride(from: 0, through: SizeX - 1, by: 1) {
                
               let EzValue = E[m , n]
                
              
                
                let LogNorm_value = LogNormalise(Real_EzValue: EzValue, RealMaxvalue: maxvalue, maxNormalisedValue: 1)
                
                
                
                
                
                
                
                
                
                
            
                    data += "\(m) \(n) \(LogNorm_value)\n"
                }
            }
        
        
        
        fileout.write_data(data: data)
        
   }
    
}





public func generateSnapshotDialectric(dt: Int){
   // Check of time is at a multiple of 10
   if(dt % 10 == 0)
   {
       // Create a new file and update frame
       let filename = "\(basename).\(frame)"
       let fileout = FileWriter(fileName: filename)
       frame += 1
       var data = ""
       // Copy
       for mm in 0 ..< SIZE {
           data += "\(electric_field[mm] + (Double(frame)-1))\n"
       }
       fileout.write_data(data: data)
   }
}
