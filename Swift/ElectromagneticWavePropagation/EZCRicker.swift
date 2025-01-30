import Foundation

public func ezINCricker(qtime: Int, location: Double, ppw: Double)-> Double { // travelling wave implementation of gaussianpulse ( ref page 100)
    
    var arg: Double = 0
    
    let qtimeDouble = Double(qtime)

    
    let a = courant * qtimeDouble - location
    let b  = ppw - 1.0
    
    let c = a / b
    
    arg = pi * c
    
    
    arg = arg * arg
    
    
    let d = 1.0
    
    let e = 2.0 * arg
    
    let f = d - e
    
   let g = exp(-arg)
    
    
    
    return f * g
    
    
}
