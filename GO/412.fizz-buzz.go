import "strconv"

/*
 * @lc app=leetcode id=412 lang=golang
 *
 * [412] Fizz Buzz
 *
 * https://leetcode.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (62.19%)
 * Likes:    917
 * Dislikes: 1212
 * Total Accepted:    345.2K
 * Total Submissions: 554.5K
 * Testcase Example:  '1'
 *
 * Write a program that outputs the string representation of numbers from 1 to
 * n.
 *
 * But for multiples of three it should output “Fizz” instead of the number and
 * for the multiples of five output “Buzz”. For numbers which are multiples of
 * both three and five output “FizzBuzz”.
 *
 * Example:
 *
 * n = 15,
 *
 * Return:
 * [
 * ⁠   "1",
 * ⁠   "2",
 * ⁠   "Fizz",
 * ⁠   "4",
 * ⁠   "Buzz",
 * ⁠   "Fizz",
 * ⁠   "7",
 * ⁠   "8",
 * ⁠   "Fizz",
 * ⁠   "Buzz",
 * ⁠   "11",
 * ⁠   "Fizz",
 * ⁠   "13",
 * ⁠   "14",
 * ⁠   "FizzBuzz"
 * ]
 *
 *
 */

// @lc code=start
func fizzBuzz(n int) []string {
	res := []string{}
	if n == 0 {
		return res
	}

	for p := 1; p <= n; p++ {
		if p%15 == 0 {
			res = append(res, "FizzBuzz")
		} else if p%5 == 0 {
			res = append(res, "Buzz")

		} else if p%3 == 0 {
			res = append(res, "Fizz")
		} else {
			res = append(res, strconv.Itoa(p))
		}
	}
	return res
}

// @lc code=end
