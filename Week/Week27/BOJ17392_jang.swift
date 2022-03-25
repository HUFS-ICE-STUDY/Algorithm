let input = readLine()!.split(separator: " ").map { Int(String($0))! }
let n = input[0]
let m = input[1]
var list = [Int]()
if n > 0 {
    list = readLine()!.split(separator: " ").map{Int(String($0))!}
}
var sum = n + list.reduce(0, +)
var ans = 0
var left = m - sum
if left <= 0 {
    print(0)
}else if left <= n+1 {
    print(left)
}else {
    let share = left / (n+1)
    let rem = left % (n+1)
    ans += rem*(share+1)*(share+2)*(2*share+3)/6
    ans += (n+1-rem)*(share)*(share+1)*(2*share+1)/6
    print(ans)
}
