import Foundation

public struct ABCgrid {
 
    let Size: Int
    
    public var data: [Double]
    
    public init( Size: Int) {
        
        self.Size = Size
        self.data = Array(repeating: 0.0, count: Size)
    }
    
    public subscript(M: Int, Q: Int, N: Int) -> Double { 
        get {
            
            return data[N * 6 + Q * 3 + M]
        }
        set {
           
            data[N * 6 + Q * 3 + M] = newValue
        }
    }
}
