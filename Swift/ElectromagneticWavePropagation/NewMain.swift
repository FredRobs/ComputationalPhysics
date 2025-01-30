//
//  NewMain.swift
//  Group4Project
//
//  Created by (s) Freddie Roberts on 28/02/2024.
//
import Foundation


public struct EMfield1D{
    
    let NumberOfNodes: Double
    
    var Ez: [Double]
    var Hy: [Double]
    let Impedance: Double
    
    let Courant: Double
    let relativePermitivity: Double
    let relativePermmeability: Double
    
    
    
    
    public init(NumberOfNodes: Double, Ez: [Double], Hy: [Double], Impedance: Double, Courant: Double, relativePermitivity: Double, relativePermmeability: Double){
        
        self.NumberOfNodes = NumberOfNodes
        self.Ez = Ez
        self.Hy = Hy
        self.Impedance = Impedance
        self.Courant = Courant
        self.relativePermitivity = relativePermitivity
        self.relativePermmeability = relativePermmeability
        
        
    }
}
