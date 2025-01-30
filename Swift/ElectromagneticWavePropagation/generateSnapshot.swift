//
//  generateSnapshot.swift
//  Group4Project
//
//  Created by (s) Freddie Roberts on 06/03/2024.
//

import Foundation

public func generateSnapshot(qTime: Int){
   // Check of time is at a multiple of 10
   if(qTime % 10 == 0)
   {
       // Create a new file and update frame
       let filename = "\(basename).\(frame)"
       let fileout = FileWriter(fileName: filename)
       frame += 1
       var data = ""
       // Copy
       for mm in 0 ..< SIZE {
           data += "\(ez[mm] + (Double(frame)-1))\n"
       }
       fileout.write_data(data: data)
   }
}
