This is an omnetpp project. You will need to have a working installation of omnetpp. Installation instructions can be found here: https://www.omnetpp.org/
This omnet project also relies on the inet4 framework. To enable the inet4 framework:
- In omnetpp, go to help->install simulation modules. Install INET Framework 4.
- If there are still errors in the project src, right click the project folder in the project explorer and select properties.
  - Properties -> Project References -> make sure inet or inet4 is checked.
- Build the inet framework by right clicking the inet directory in the project explorer and select build project.

To run our project:
- we made a few changes to the inet framework. It would be much easier to clone our modified framework into the same workspace as omnet and create a symbolic link from our modifed inet to match the current name of the installed inet.
  - For example, if the workspace contains our_project, inet. (inet in this case is the unmodified inet)
    - git clone git@github.com:lol-fi/inetchanges.git
    - the workspace should now contain our_project, inet, inetchanges.
    - The easiest way to use our inet changes without much hassle is to rename inet [mv inet inet_original], then link inetchanges as inet [ln -s inetchanges inet].
- back in omnet, you will most likely need to rebuild inet (since this is now containing our changes).
- once that is complete, running should be as simple as going to the right ini file (omnetpp.ini, omnetpp_jitter.ini, omnetpp_rts.ini), and clicking the green run button.

Graph Generation:
- to create the graphs we generated, open General.anf.
- Under the browse data tab, filter the module by "*app*thread*" and the statistic name by "packetRec*". Essentially, we are looking for the packets received at the application level only.
- You can double click the folder and apply sum to the new graph. This will keep a running sum of all the packets received. To apply lines between each data point, right click the graph, click properties, and under line type, click linear.


