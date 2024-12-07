use std::io;

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    let stdin = io::stdin(); 


    let mut total = 0;
    // Read in the puzzle
    while stdin.read_line(&mut buffer).is_ok_and(|x| x > 1) {

        let cols: Vec<&str> = buffer.trim().split_whitespace().collect();

        let target = cols[0].replace(":", "").parse::<i64>().unwrap();

        let mut stack: Vec<(&str,Vec<i64>)> = Vec::new();

        let nums: Vec<i64> = cols[1..].iter().map(|c| {
            return c.parse::<i64>().unwrap();
        }).collect();
        stack.push(("+", nums.clone()));
        stack.push(("*", nums.clone()));        
        stack.push(("||", nums.clone()));   

        let mut row_done = false;
        while !stack.is_empty() && !row_done {
            let (op, ns) = stack.pop().unwrap();
            // println!("'{}' {:?}", op, ns);
            let mut nvec: Vec<i64>= Vec::new();
            if ns.len() == 1 {
                if ns[0] == target {
                    total = total + target;
                    row_done = true;
                }
                continue;
            } else if op == "+" {
                let t = ns[0] + ns[1];
                if t <= target {
                    nvec.push(t);
                } else {
                    continue;
                }
            } else if op == "*" {
                let t = ns[0] * ns[1];
                if t <= target {
                    nvec.push(t);
                } else {
                    continue;
                }
            } else if op == "||" {
                let combined = ns[0].to_string() + &ns[1].to_string();
                let t = combined.parse::<i64>().unwrap();
                if t <= target {
                    nvec.push(t);
                } else {
                    continue;
                }
            }

            let mut i = 2;
            while i < ns.len() {
                nvec.push(ns[i]);
                i = i + 1;
            }
            // println!("{:?}", nvec);
            stack.push(("+", nvec.clone()));
            stack.push(("*", nvec.clone()));
            stack.push(("||", nvec.clone()));

        }

        println!("{:?}", cols);
        buffer = String::new();
    }


    print!("Part 1: {}\n", total);

    Ok(())
}