extern crate regex;

use std::collections::HashMap;
use std::collections::VecDeque;
use std::io;
use regex::Regex;


#[derive(Debug)]
enum Op {
    XOR,
    OR,
    AND,
    UNDEFN
}

fn main() -> io::Result<()> {
    let lines = io::stdin().lines();
    let mut vars: HashMap<String, u32> = HashMap::new();
    let mut fns: Vec<(String, Op, String, String)> = Vec::new();

    let re1 = Regex::new(r"^([a-z][0-9][0-9]): ([01])").unwrap();
    let re2 = Regex::new(r"^([a-z0-9]+) ([A-Z]+) ([a-z0-9]+) -> ([a-z0-9]+)").unwrap();

    for line in lines {
        let l = line.unwrap();
        println!("{}", &l);

        re1.captures(&l).map( |cap| vars.insert(cap[1].to_string(), cap[2].parse::<u32>().unwrap()));

        re2.captures(&l).map( |cap| fns.push((cap[1].to_string(), to_op(&cap[2]), cap[3].to_string(), cap[4].to_string())));

    }
    println!("{:?}", vars);
    println!("{:?}", fns);

    let xinput = to_dec(&vars, "x");
    let yinput = to_dec(&vars, "y");
    let target = xinput + yinput;

    println!("x+y: {}", target);

    solve(vars, fns);
   
       
    Ok(())
}

fn solve(inputs: HashMap<String, u32>,  functions: Vec<(String, Op, String, String)>) -> isize {
    let mut fns = VecDeque::from(functions);
    let mut vars = HashMap::from(inputs);
    while !fns.is_empty() {
        let (x, o, y, r) = fns.pop_front().unwrap();
        if vars.contains_key(&x) && vars.contains_key(&y) {
            let vx = vars[&x];
            let vy = vars[&y];

            match o {
                Op::OR => {
                    if vx == 1 || vy == 1 { 
                        vars.insert(r, 1);
                    } else {
                        vars.insert(r,0);
                    }
                },
                Op::XOR => {
                    let t = vx + vy;
                    if t == 1 {
                        vars.insert(r,1);
                    } else {
                        vars.insert(r,0);
                    }
                }
                Op::AND => {
                    if vx == 1 && vy == 1 {
                        vars.insert(r,1);
                    } else {
                        vars.insert(r,0);
                    }
                }
                Op::UNDEFN => {}
            }
        } else {
            fns.push_back((x,o,y,r));
        }
    }

    return to_dec(&vars, &"z");
}

fn to_dec(vars: &HashMap<String, u32>, prefix: &str) -> isize {
    let mut zs: Vec<(&String, &u32)> = vars.iter().filter(|(k,_)| k.starts_with(prefix)).collect::<Vec<(&String, &u32)>>();
    zs.sort_by(|(k,_), (k1, _)| k.cmp(k1).reverse());

    let binstr :String = zs.iter().map(|(_,v)| std::char::from_digit(**v, 2).unwrap()).collect();
    let decval = isize::from_str_radix(&binstr, 2).unwrap();
    println!("{}: {} {}", prefix, binstr, decval); 
    return decval;
}
 
fn to_op(s: &str) -> Op {
    return match s {
        "XOR" => Op::XOR,
        "OR" => Op::OR,
        "AND" => Op::AND,
        _ => Op::UNDEFN,
    }
}