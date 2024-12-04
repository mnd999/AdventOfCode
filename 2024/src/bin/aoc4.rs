use std::io;

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    let stdin = io::stdin(); 


    let mut puzzle = Vec::new();

    let mut row_cnt = 0;
    // Read in the puzzle
    while stdin.read_line(&mut buffer).is_ok_and(|x| x > 1) {

        let mut row = Vec::new();

        let mut i = 0;
        for c in buffer.chars() {
            if c != '\n' {
                row.push(c);    
                i = i + 1;
            }
        }

        buffer = String::new();
        puzzle.push(row);
        row_cnt = row_cnt + 1;
    }

    let mut total = 0;
    let mut x = 0;
    let mut y = 0;
    while x < row_cnt {
        while y < puzzle[x].len() {
            total = total + find_xmas_at(&puzzle, x, y);
            y = y + 1;
        }
        x = x + 1;
        y = 0;
    }


    print!("{}\n", row_cnt);
    print!("{:?}\n", puzzle);
    print!("Part 1: {}\n", total);

    Ok(())
}


fn find_xmas_at(puzzle: &Vec<Vec<char>>, x: usize, y: usize) -> i32 {

    let mut tot = 0;

    if puzzle[x][y] != 'X' {
        // println!("({},{}), tot: {}", x, y, tot);
        return 0;
    }

    // Backwards
    if x> 2 && puzzle[x][y] == 'X' && puzzle[x-1][y] == 'M' && puzzle[x-2][y] == 'A' && puzzle[x-3][y] == 'S' {
        tot = tot + 1;
    }

    // Forwards
    if x < (puzzle[x].len() - 3) && puzzle[x][y] == 'X' && puzzle[x+1][y] == 'M' && puzzle[x+2][y] == 'A' && puzzle[x+3][y] == 'S' {
        tot = tot + 1;
    }

    // Up
    if y> 2 && puzzle[x][y] == 'X' && puzzle[x][y-1] == 'M' && puzzle[x][y-2] == 'A' && puzzle[x][y-3] == 'S' {
        tot = tot + 1;
    }

    // Down
    if y < (puzzle.len() - 3) && puzzle[x][y] == 'X' && puzzle[x][y+1] == 'M' && puzzle[x][y+2] == 'A' && puzzle[x][y+3] == 'S' {
        tot = tot + 1;
    }

    // Backwards / Up
    if x> 2 && y > 2 && puzzle[x][y] == 'X' && puzzle[x-1][y-1] == 'M' && puzzle[x-2][y-2] == 'A' && puzzle[x-3][y-3] == 'S' {
        tot = tot + 1;
    }

    // Backwards / Down
    if x> 2 && y < (puzzle.len() - 3) && puzzle[x][y] == 'X' && puzzle[x-1][y+1] == 'M' && puzzle[x-2][y+2] == 'A' && puzzle[x-3][y+3] == 'S' {
        tot = tot + 1;
    }

    // Forwards / Up
    if x < (puzzle[x].len() - 3) && y > 2 && puzzle[x][y] == 'X' && puzzle[x+1][y-1] == 'M' && puzzle[x+2][y-2] == 'A' && puzzle[x+3][y-3] == 'S' {
        tot = tot + 1;
    }

    // Forwards / Down
    if x < (puzzle[x].len() - 3) && y < (puzzle.len() - 3) && puzzle[x][y] == 'X' && puzzle[x+1][y+1] == 'M' && puzzle[x+2][y+2] == 'A' && puzzle[x+3][y+3] == 'S' {
        tot = tot + 1;
    }


    println!("({},{}), tot: {}", x, y, tot);

    return tot;
}