import Foundation

// 1D Constants

//definitions
public let electric_times_spatial_difference_magnetic = cezh
public let electric_times_previous_electric = ceze
public let magnetic_times_previous_magnetic = chyh
public let magnetic_times_spatial_difference_electric = chye

// Variables
//public let basename = "snapshot"
public let hardwireSourceNode = 50
//var frame = 0
public let SIZE = 200
public let LOSS_LAYER = 180
public let LOSS = 0.02
public let relativePermittivity = 9.0
public let impedance = 377.0
public let total_steps = 450
public var materialData = ""
let dt = 0.01

public var electric_field = Array(repeating: 0.0, count: SIZE)
public var magnetic_field = Array(repeating: 0.0, count: SIZE)
public var polarizationCurrent = Array(repeating: 0.0, count: SIZE)
public var ceze = Array(repeating: 0.0, count: SIZE)
public var cezh = Array(repeating: 0.0, count: SIZE)
public var chyh = Array(repeating: 0.0, count: SIZE)
public var chye = Array(repeating: 0.0, count: SIZE)

public let PermittivityFreeSpace = 8.85e-12
public let PermittivitySilicon = PermittivityFreeSpace * 11.7

public var Epsr: Double = 0.0



//2D constants====================


public var qTime = 0

public let MaxTime = 500

public let numberOfRows = 81

public let numberOfColumns = 101



public let imp0 = 377.0

public let pi = Double.pi

public let courant = 1.0 / sqrt(2)





//snapshot initialisations

public let SizeX = 101
public let SizeY = 81
public var frame: Int = 0
public var startTime = 10
public var startNodeX = 0
public var endNodeX = 101
public var spatialStrideX = 1
public var startNodeY = 0
public var endNodeY = 81
public var spatialStrideY = 1
public let basename = "snapshot"

//TFSF INitialisations
public var coef0: Double = 0.0
public var coef1: Double = 0.0
public var coef2: Double = 0.0

public var EzLeft = ABCgrid(Size: (numberOfRows) * 6)
public var EzRight = ABCgrid(Size: (numberOfRows ) * 6)
public var EzTop = ABCgrid(Size: (numberOfColumns ) * 6)
public var EzBottom = ABCgrid(Size: (numberOfColumns ) * 6)




//2D CONSTANTS


public let courantximp = courant * imp0
    
public let courantDIVimp = courant / imp0



// 2D Grid variables

public var Ez = twoDGrid(columns: numberOfColumns, rows: numberOfRows, initialValue: 0.0)

public var Hx = twoDGrid(columns: numberOfColumns , rows: numberOfRows - 1, initialValue: 0.0)

public var Hy = twoDGrid(columns: numberOfColumns - 1, rows: numberOfRows , initialValue: 0.0)


public var Chxe = twoDGrid(columns: numberOfColumns , rows: numberOfRows - 1, initialValue: 0.0)

public var Chye = twoDGrid(columns: numberOfColumns - 1, rows: numberOfRows , initialValue: 0.0)

public var Ceze = twoDGrid(columns: numberOfColumns, rows: numberOfRows, initialValue: 0.0)



public var Chxh = twoDGrid(columns: numberOfColumns , rows: numberOfRows - 1, initialValue: 0.0)

public var Chyh = twoDGrid(columns: numberOfColumns - 1, rows: numberOfRows, initialValue: 0.0)

public var Cezh = twoDGrid(columns: numberOfColumns, rows: numberOfRows, initialValue: 0.0)







// constants needed for 1D aux
public let Nloss = 20
public let MaxLoss = 0.35

public var Xsize = 101

//Xsize += Nloss






// ABC Variables for Auxillary 1D grid

public var Hy1DAux = Array(repeating: 0.0, count: Xsize - 1)
public var Chyh1Daux = Array(repeating: 0.0, count: Xsize - 1)
public var Chye1Daux = Array(repeating: 0.0, count: Xsize - 1)

public var Ez1Daux = Array(repeating: 0.0, count: Xsize)
public var Ceze1Daux = Array(repeating: 0.0, count: Xsize)
public var Cezh1Daux = Array(repeating: 0.0, count: Xsize)





//TFSF region

public let firstX = 5
public let firstY = 5
public let lastX = 95
public let lastY = 75

