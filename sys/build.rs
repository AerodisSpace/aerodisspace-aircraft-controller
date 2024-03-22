use std::fs;
use std::path::Path;

fn main() {
    let files = ["src/gamepad.rs", "src/packet.rs"];
    cxx_build::bridges(files).compile("sys_aircraft_controller");

    println!("cargo:rerun-if-changed=src/lib.rs");
    println!("cargo:rerun-if-changed=src/gamepad.rs");
    println!("cargo:rerun-if-changed=src/packet.rs");

    let source_dir = Path::new("./target/cxxbridge/sys/src");
    let cxx_dir = Path::new("./target/cxxbridge/rust");
    let target_dir = Path::new("../src/generated");

    if let Ok(entries) = fs::read_dir(cxx_dir) {
        for entry in entries {
            if let Ok(entry) = entry {
                let source_file_path = source_dir.join(entry.file_name());
                let target_file_path = target_dir.join(entry.file_name());

                if let Err(e) = fs::copy(&source_file_path, &target_file_path) {
                    eprintln!("Error copy file: {}", e);
                }
            }
        }
    }
    if let Ok(entries) = fs::read_dir(source_dir) {
        for entry in entries {
            if let Ok(entry) = entry {
                let source_file_path = source_dir.join(entry.file_name());
                let target_file_path = target_dir.join(entry.file_name());

                if let Err(e) = fs::copy(&source_file_path, &target_file_path) {
                    eprintln!("Error copy file: {}", e);
                }
            }
        }
    }
}
