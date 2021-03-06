//
// Created by manuelli on 1/30/17.
//

#include "kuka_iiwa_status_to_residual.h"
#include "drake/common/drake_path.h"
#include <thread>
#include <cstdlib>

int main( int argc, char* argv[]) {
  using namespace drake;
  using namespace examples;
  using namespace ContactParticleFilter;

  std::string spartan_source_dir = std::getenv("SPARTAN_SOURCE_DIR");
  std::string config_filename = spartan_source_dir + "/src/ContactParticleFilter/config/iiwa_status_to_residual.yaml";

  std::cout << "path to file is " << config_filename << std::endl;
  KukaIIWAStatusResidualConfig config = parseConfig(config_filename);
  KukaIIWAStatusToResidual translator = KukaIIWAStatusToResidual(config);

  translator.Start();
  std::thread & lcm_thread_handle = translator.lcm_handler_.ThreadHandle;
  lcm_thread_handle.join();
}

