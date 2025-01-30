//
//  updating ez:hy.swift
//  Group4Project
//
//  Created by (s) Cate Georgescu on 06/03/2024.
//

import Foundation

func update_electric(ez: inout[Double], hy: [Double], imp0: Double, qTimeSubtract30: Double) {
    let SIZE = ez.count
    ez[0] = ez[1]
    ez[SIZE - 1] = ez[SIZE - 2]
    for mm in 1..<SIZE {
        ez[mm] = ceze[mm] * ez[mm] + cezh[mm] * (hy[mm] - hy[mm - 1])
    }
    ez[hardwireSourceNode] += exp(-(qTimeSubtract30) * (qTimeSubtract30) / 100.0)
}

func update_magnetic(ez: [Double], hy: inout[Double], imp0: Double, qTimeSubtract30: Double) {
    let SIZE = hy.count
    hy[SIZE - 1] = hy[SIZE - 2]
    for mm in 0..<(SIZE - 1) {
        hy[mm] = chyh[mm] * hy[mm] + chye[mm] * (ez[mm + 1] - ez[mm])
    }
    hy[hardwireSourceNode - 1] -= exp(-(qTimeSubtract30) * (qTimeSubtract30) / 100.0) / imp0
}
