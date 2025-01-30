import Cocoa

import Foundation

//let Nloss = 20

Xsize += Nloss

    


let InitialiseConstantsForGivenDimension = _1Dor2D(choose1Dor2D: 2)

let DoTimeDialectric = TDialectric_yes_or_no(_0forno_1foryes: 1)



InitialiseConstantsForGivenDimension



    
if InitialiseConstantsForGivenDimension == 1 && DoTimeDialectric == 1{
    


    for qtime in 0..<MaxTime {


        Epsr =  smoothTransitionDielectric(currentTime: Double(qtime) , 40.0, 20.0, 2 * PermittivityFreeSpace, 2 * (1.5625 * PermittivityFreeSpace))

        let qTimeSubtract30 = Double(qtime) - 30.0

        magnetic_field[SIZE - 1] = magnetic_field[SIZE - 2]

        for mm in 0..<(SIZE - 1) {
            magnetic_field[mm] = magnetic_field[mm] + (electric_field[mm + 1] - electric_field[mm]) / imp0
        }
        magnetic_field[hardwireSourceNode - 1] -= exp(-(qTimeSubtract30) * (qTimeSubtract30) / 100.0) / imp0



    electric_field[0] = electric_field[1]
    electric_field[SIZE - 1] = electric_field[SIZE - 2]


    for mm in 1..<SIZE {

        let qTimeSubtract30 = Double(qtime) - 30.0



        electric_field[mm] = electric_field[mm] + (magnetic_field[mm] - magnetic_field[mm - 1]) * imp0 / Epsr

        electric_field[hardwireSourceNode] += exp(-(qTimeSubtract30) * (qTimeSubtract30) / 100.0)
    }


    generateSnapshotDialectric(dt: qtime)



}

}else if InitialiseConstantsForGivenDimension == 1 && DoTimeDialectric == 0{

    for qtime in 0..<MaxTime {







        updateMagnetic(_1or2: InitialiseConstantsForGivenDimension, time: qtime)


        updateElectric(_1or2: InitialiseConstantsForGivenDimension, time: qtime)

            // update_polarizationCurrent(J: &polarizationCurrent, ez: electric_field, E_temp: temp_electric)

            generateSnapshot1D(dt: qtime)

            }

    }



else{



            for qtime in 0..<MaxTime {

                updateMagnetic(_1or2: InitialiseConstantsForGivenDimension, time: qtime)

                   // UpdateTFSFunction(time: qtime, Xsize: Xsize)


                updateElectric(_1or2: InitialiseConstantsForGivenDimension, time: qtime)


               //   WaveguideBoundary2D()


                   Ez[(numberOfColumns - 1) / 2, (numberOfRows - 1) / 2] = ezINCricker(qtime: qtime, location: 0.0, ppw: 20)


                ABCFunc()


                snapshot2d(qtime: qtime, ez: Ez, temporalStride: 1)



    }



}











