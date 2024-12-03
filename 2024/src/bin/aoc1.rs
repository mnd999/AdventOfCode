use std::io;
use std::collections::HashMap;

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    let stdin = io::stdin(); 
    let mut left: Vec<i32> = Vec::new();
    let mut right: Vec<i32> = Vec::new();

    while stdin.read_line(&mut buffer).is_ok_and(|x| x > 1) {
        let cols: Vec<&str> = buffer.split_whitespace().collect();
        left.push(cols[0].parse::<i32>().unwrap());
        right.push(cols[1].parse::<i32>().unwrap());
        buffer = String::new();
    }

    left.sort();
    right.sort();

    let mut total = 0;
    let mut i = 0;
    while i < left.len() {
        total += (left[i] - right[i]).abs();
        i = i + 1;    
    }

    print!("Part 1: {}\n", total);

    let mut counts = HashMap::new();

    for num in right {
        let _  = if !counts.contains_key(&num) {
            counts.insert(num, 1)
        } else {
            counts.insert(num, counts.get(&num).unwrap() + 1)
        };
    }


    let mut total2 = 0;
    for num in left {
        let v = if counts.contains_key(&num) {
            counts.get(&num).unwrap() * num 
        } else {
            0
        };
        println!("{}   {}", num, v);
        total2 = total2 + v;
    }

    print!("Part 2: {}\n", total2);


    Ok(())
}