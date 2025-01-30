import Foundation


public struct twoDGrid {
    let columns: Int
    let rows: Int
    public var data: [[Double]]

    public init(columns: Int, rows: Int, initialValue: Double) {
        self.columns = columns
        self.rows = rows
        self.data = Array(repeating: Array(repeating: initialValue, count: columns), count: rows)
        
    }

    public subscript(column: Int, row: Int) -> Double {
        get {
            precondition(column >= 0 && column < columns, "Index out of range")
            precondition(row >= 0 && row < rows, "Index out of range")
            return data[row][column]
        }
        set {
            precondition(column >= 0 && column < columns, "Index out of range")
            precondition(row >= 0 && row < rows, "Index out of range") 
            data[row][column] = newValue
        }
    }
}



