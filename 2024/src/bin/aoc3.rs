extern crate regex;

use std::io;
use regex::Regex;

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    let stdin = io::stdin(); 

    while stdin.read_line(&mut buffer).is_ok_and(|x| x > 1) {

        let re = Regex::new(r"mul\(([0-9]+),([0-9]+)\)").unwrap();

        let vals : Vec<i32> = re.captures_iter(&buffer).map(|caps| {
            let (_, [x, y]) = caps.extract();
            x.parse::<i32>().unwrap() * y.parse::<i32>().unwrap()
        }).collect();

        let sum = vals.iter().fold(0, |acc, x| acc + x);

        print!("{:?}, {}\n", vals, sum);

        let re2 = Regex::new(r"(mul|do|don't)(\(([0-9]+),([0-9]+)\)|\(()()\))").unwrap();

        let vals2 : Vec<(&str, &str, &str)> = re2.captures_iter(&buffer).map(|caps| {
            let (_, [cmd, _, x, y]) = caps.extract();
            (cmd, x,y)
        }).collect();

        let mut total = 0;
        let mut state = 1;
        for (cmd, x, y) in vals2 {
            if cmd == "don't" {
                state = 0;
            }
            if cmd == "do" {
                state = 1;
            }
            if cmd == "mul" && state == 1 {
                total = total + x.parse::<i32>().unwrap() * y.parse::<i32>().unwrap()
            }
        }        

        print!("Total: {}\n", total);

    }


    print!("Part 1: {}\n", "");


    print!("Part 2: {}\n", "");

    Ok(())
}
