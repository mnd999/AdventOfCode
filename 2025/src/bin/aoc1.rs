use std::io;

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    let stdin = io::stdin(); 


    let mut pos = 50;
    let mut zerocnt = 0;
    let mut zerocnt2 = 0;
    let mut row_cnt = 0;
    // Read in the puzzle
    while stdin.read_line(&mut buffer).is_ok_and(|x| x > 1) {

        let (dir, nstr) = buffer.trim().split_at(1);
        let val = nstr.parse::<i32>().unwrap();

        println!("{}", buffer);

        for _n in 0..val {
            if dir == "L" {
                pos = pos - 1;
                if pos == 0 {
                    zerocnt2 += 1;
                }
                if pos == -1 {
                    pos = 99
                }
            } else if dir == "R" {
                pos = pos + 1;
                if pos == 100 {
                    pos = 0;
                    zerocnt2 += 1
                }
            } else {
                panic!("Unknown direction");
            }
        }

        if pos == 0 {
            zerocnt +=1;
        }

        println!("{} {} {} {}", pos, val, zerocnt, zerocnt2);

        row_cnt = row_cnt + 1;
        buffer.clear();
    }

    print!("Part 1: {}\n", zerocnt);
    print!("Part 2: {}\n", zerocnt2);

    Ok(())
}
