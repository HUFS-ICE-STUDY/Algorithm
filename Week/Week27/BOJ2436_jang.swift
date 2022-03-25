import Foundation

let input = readLine()!.split(separator: " ").map { Double(String($0))! }
let n = input[0]
let m = input[1]
let temp = m/n

var a = 0
var b = 0

var count = 0
var able = true

var ansA = 0
var ansB = 0

for i in 1...Int(sqrt(temp)) {
    if Int(temp) % i == 0 {
        a = i
        b = Int(temp)/i
        count = 0
        able = true
        
        for j in 1...a {
            if (a%j == 0) && (b%j == 0) {
                count += 1
            }
            if count > 1 {
                able = false
                break
            }
        }
        if able {
            ansA = a * Int(n)
            ansB = b * Int(n)
        }
    }
}
print(ansA, ansB)
