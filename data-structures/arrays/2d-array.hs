package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
    "math"
)

// Complete the hourglassSum function below.
func hourglassSum(arr [][]int32) int32 {
    var sum, max int32
    results := make(chan int32)
    expected := 0
    for i := 0; i < len(arr) - 2; i++ {
        for j := 0; j < len(arr[i]) - 2; j++ {
            go func(i, j int) {
                var sum int32
                for k := 0; k < 3; k++ {
                    for l := 0; l < 3; l++ {
                        if k != 1 || l == 1 {
                            sum += arr[i+k][j+l]
                        }
                    }
                }
                results <- sum
            }(i, j)           
            expected++     
        }
    }

    sum = math.MinInt32
    for expected > 0 {
        sum = <-results
        if sum > max {
            max = sum
        }
        expected--
    }

    return max
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)

    defer stdout.Close()

    writer := bufio.NewWriterSize(stdout, 1024 * 1024)

    var arr [][]int32
    for i := 0; i < 6; i++ {
        arrRowTemp := strings.Split(readLine(reader), " ")

        var arrRow []int32
        for _, arrRowItem := range arrRowTemp {
            arrItemTemp, err := strconv.ParseInt(arrRowItem, 10, 64)
            checkError(err)
            arrItem := int32(arrItemTemp)
            arrRow = append(arrRow, arrItem)
        }

        if len(arrRow) != int(6) {
            panic("Bad input")
        }

        arr = append(arr, arrRow)
    }

    result := hourglassSum(arr)

    fmt.Fprintf(writer, "%d\n", result)

    writer.Flush()
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err != nil {
        panic(err)
    }
}

