import Foundation

public func MaxValue(data: [[Double]]) -> Double {
 
    let flattenedData = data.flatMap{$0}
    
    
    let absValues = flattenedData.map {$0}
    
    
    let maxAbsVal = absValues.max() ?? 0.0
    
 
    
    return maxAbsVal
}






public func LogNormalise(Real_EzValue: Double, RealMaxvalue: Double, maxNormalisedValue: Double) -> Double{

    let realmin: Double = 1e-9

    let a = Real_EzValue + realmin

    let b = RealMaxvalue

    let scalefactor = maxNormalisedValue / b

    let c = abs(a * scalefactor)



    let LOGGED = log10(c)



    return LOGGED

}




