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

        print!("{:?}, {}", vals, sum);
    }


    print!("Part 1: {}\n", "");


    print!("Part 2: {}\n", "");

    Ok(())
}
