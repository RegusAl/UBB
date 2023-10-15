package Factory;

import Enum.ContainerStrategy;
import Container.Container;

public interface Factory {
    Container createContainer(ContainerStrategy strategy);
}
