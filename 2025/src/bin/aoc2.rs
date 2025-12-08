use std::cmp;
use std::io;

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    let stdin = io::stdin(); 

    let mut ranges: Vec<Vec<i64>> = Vec::new();
    let mut total = 0;
    let mut total2 = 0;
    let mut row_cnt = 0;
    // Read in the puzzle
    while stdin.read_line(&mut buffer).is_ok_and(|x| x > 1) {

        ranges = buffer.trim().split(",").map(
            |r| r.to_owned().split("-").map(|n| n.to_owned().parse::<i64>().unwrap()).collect()
        ).collect();

        row_cnt = row_cnt + 1;
    }

    for i in ranges.iter() {
        for n in i[0]..(i[1] + 1) {
            if has_repeats(n) {
                total += n;
            }
            if has_repeats2(n) {
                total2 += n;
            }
        }
    }


    print!("Part 1: {:#?}\n", total);
    print!("Part 2: {}\n", total2);

    Ok(())
}

fn has_repeats(num: i64) -> bool {

    let s = num.to_string();
    let length = s.chars().count();
    if (length % 2) != 0 {
        return false;
    }
    println!("Num: {} ", num);
    

    let slicelength = (s.chars().count() / 2); 

    if s.get(0..slicelength).unwrap() == s.get(slicelength..length).unwrap() {
        return true;
    }


    println!("");

    return false;
}


fn has_repeats2(num: i64) -> bool {

    let s = num.to_string();
    println!("Num: {} ", num);

    let slicelength = (s.chars().count() / 2); 
    for n in 1..slicelength+1{
       let mut okay = true; 
       let r = s.get(0..n).unwrap();
       println!("sl:{}, r:{}", slicelength,r);
       for x in (n..(s.chars().count())).step_by(n) {
            println!("x: {}",x );
            let end = cmp::min(x+n, s.chars().count());
            let next = s.get(x..end).unwrap(); 
            println!("next: {}", next);
            if r != next {
                okay = false;
            }
       }
       if okay {
        println!("Found: {}", num);
        return true;
      }
    }

    println!("");

    return false;
}
