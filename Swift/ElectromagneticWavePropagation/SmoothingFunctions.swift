import Foundation

func sigmoidFunction(_ t: Double, _ startTime: Double, _ transitionTime: Double) -> Double {
    let endTime = startTime + transitionTime
    if t < startTime {
        return 0.0
    } else if t > endTime {
        return 1.0
    } else {
        return 0.5 * (1 + tanh((t - startTime - transitionTime / 2) / (transitionTime / 2)))
    }
}

public func smoothTransitionDielectric(currentTime t: Double, _ startTime: Double, _ transitionTime: Double, _ initialEpsilon: Double, _ finalEpsilon: Double) -> Double {
    let sigmoid = sigmoidFunction(t, startTime, transitionTime)
    return initialEpsilon + sigmoid * (finalEpsilon - initialEpsilon)
}
