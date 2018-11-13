//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.inet.StandardHost;
import inet.node.inet.Router;
import inet.node.ethernet.EtherSwitch;
import inet.node.ethernet.Eth1G;
import inet.common.queue.IOutputQueue;
import inet.common.misc.ThruputMeter;



network WiredNetworkExample
{
    parameters:
        int numServers; // number of clients in the network

    submodules:
        configurator: Ipv4NetworkConfigurator;
        client: thruput_host { // predefined standard host
            @display("p=178,94");
        }
        switch: EtherSwitch;
        server[numServers]: thruput_host;
    connections: // network level connections
        switch.ethg++ <--> Eth1G <--> client.ethg++; // bidirectional ethernet
        for i=0..numServers-1 {
            server[i].ethg++ <--> Eth1G <--> switch.ethg++; // ethernet
        }
}
